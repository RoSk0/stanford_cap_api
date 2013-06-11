core = 7.x
api = 2
projects[drupal][type] = core

; Contrib modules
projects[views][type] = module
projects[views][subdir] = "contrib"

projects[features][type] = module
projects[features][subdir] = "contrib"

projects[strongarm][type] = module
projects[strongarm][subdir] = "contrib"

projects[ctools][type] = module
projects[ctools][subdir] = "contrib"

projects[date][type] = module
projects[date][subdir] = "contrib"

; Custom modules
;projects[stanford_cap_api][type] = module
;projects[stanford_cap_api][subdir] = "custom"
;projects[stanford_cap_api][download][type] = git
;projects[stanford_cap_api][download][url] = http://git.drupal.org/project/views.git
