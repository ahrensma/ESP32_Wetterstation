#!/bin/bash
set -e

# Usage: ./create_release.sh <tag_name> "<release_title>" "<release_notes>"
if [ "$#" -ne 3 ]; then
  echo "Usage: $0 <tag_name> \"<release_title>\" \"<release_notes>\""
  exit 1
fi

TAG_NAME=$1
RELEASE_TITLE=$2
RELEASE_NOTES=$3
REPO="ahrensma/ESP32_Wetterstation"

# Build exclusion patterns for zip from .gitignore:
# - Ignores empty lines and comments
EXCLUDE_ZIP=()
while IFS= read -r line; do
  # Skip empty lines and comments
  [[ -z "$line" ]] && continue
  [[ "$line" =~ ^# ]] && continue
  # Adjust pattern if necessary (e.g., append '/*' for directories)
  EXCLUDE_ZIP+=("-x" "$line")
done < .gitignore

echo "Creating ZIP archive..."
# Exclude the .git folder manually
zip -r my_project.zip . -x ".git/*" "${EXCLUDE_ZIP[@]}"

echo "Creating TAR.GZ archive..."
# Use tar's --exclude-from to exclude patterns from .gitignore.
# Also exclude the .git folder.
tar --exclude='.git' --exclude-from=.gitignore -czvf my_project.tar.gz .

echo "Creating GitHub release..."
# Create the release on GitHub using the GitHub CLI (gh)
gh release create "$TAG_NAME" my_project.zip my_project.tar.gz --repo "$REPO" --title "$RELEASE_TITLE" --notes "$RELEASE_NOTES"

# Optional: clean up the archive files after release creation
rm my_project.zip my_project.tar.gz

echo "Release created successfully."
