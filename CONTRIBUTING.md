# Github Dev Workflow
All developers should follow the following steps when working on their features:
## Why we use Git?
- It gives every developer their own local copy of the entire project. This isolated environment lets each developer work independently of all other changes to a project—they can add commits to their local repository and completely forget about upstream developments
- It gives you access to Git’s robust branching and merging model. Git branches are designed to be a fail-safe mechanism for integrating code and sharing changes between repositories.
## How it works
The Centralized Workflow uses a central repository to serve as the single point-of-entry for all changes to the project. The default development branch is called master and all changes are committed into this branch.

You start by forking the central repository, then clone your own repo to your disk. In your own local copies of the project, you can edit files and commit changes to your own repo. If you are happy about what has been done, you can “push” local branch to your repo, then issue a pull request waiting for administrator to merge your repo into the central repository.
## First time only setup steps:
- login to your own github account
- Fork the CUHKSZLib private repos into your account, aka, "your repos"
- Clone "your repos" to local computer (DO NOT clone the alesiong/CUHKSZLib or any other repo directly)

  `git clone https://github.com/youraccount/CUHKSZLib.git`

- Check current upstream repo `git remote -v`
- Add new upstream to local repo

  `git remote add upstream https://github.com/alesiong/CUHKSZLib.git`

## Steps when working on a new feature:
- Merge the latest version of upstream repo to the local master branch

  `git pull upstream master # git pull <remote> <branch>`
- Start working on a new feature by creating a new branch called "yourfeature#issuenumber"

  `git branch yourfeature#issuenumber`

  `git checkout yourfeature#issuenumber`
  or
  `git checkout -b yourfeature#issuenumber`

- Work on the feature, commit as many as you want to the yourfeature#issuenumber branch of you own local repo

  `git commit -am 'write something here to remind you what you did' # -a commit all changes -m commit with a message`
  * commit certain file: `git commit <file>`

- If you have created new files which may be untracked(use `git status` or `gst` to check out), you need to add them to the index:

  `git add <file>`

- Once the feature is complete, push all changes to your yourfeature#issuenumber branch

  `git commit -am 'finished the feature'`

  `git push origin yourfeature#issuenumber # git push <remote> <branch>`

- Use OpsWorks to upload your code to AWS for testing (see conf-cookbook repo for instructions)

- Then, go to github.com and issue a pull request using the branch

## Code review:
Once there is a pull request, another person will review the changes and leave inline comments.

## Revisions:
The developer will see the comments and make changes and additional commits (these new commits will show in the pull request automatically, one pull request maps to one branch)

## Final review and merge:
The changes are reviewed and merged. Some merges might result in conflicts, which must be resolved by using the command line. Once merged and pushed, the pull request will be closed automatically.

Once the pull request is merged, the yourfeature#issuenumber branch can be removed.

## Test something quickly on OpsWorks and rollback

If you want to test something quickly on the server and rollback, here is the workflow: develop something such as adding /test500 route, commit, git push to your repo, opsworks will update automatically. After testing, you need to roll back locally, do `git log` to find the previous commit number such as 12345, then `git reset --hard 12345`, then force your remote repo to sync with your local “old” code `git push -f`

## Links
https://www.atlassian.com/git/tutorials/comparing-workflows/centralized-workflow

http://git-scm.com/docs/git-commit

http://git-scm.com/docs/git-add

https://www.atlassian.com/git/tutorials/syncing/
