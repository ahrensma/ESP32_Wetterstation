git init
git status
git checkout -b main
git add .
git commit -m "Initial commit on main branch"
git checkout -b development
git branch
git remote add origin https://github.com/ahrensma/test.git
git push -u origin main
git push -u origin **development**
git checkout development
git pull origin development
git checkout -b test
git add .
git status # Verify staged changes
git commit -m "Implement feature or test changes"
git checkout development
git merge test
git push origin development
git checkout main
git merge development
git push origin main
git branch -d test
git push origin --delete test
