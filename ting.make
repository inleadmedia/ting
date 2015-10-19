api = 2
core = 7.x

; Contrib

// The patch allows extra CURL parameters.
projects[nanosoap][subdir] = "contrib"
projects[nanosoap][version] = "1.0"
projects[nanosoap][patch][] = "http://drupal.org/files/nanosoap-curloptions-1943732.patch"

; Libraries
libraries[ting-client][download][type] = "git"
libraries[ting-client][download][url] = "git@github.com:easyddb/ting-client.git"
libraries[ting-client][download][tag] = "7.x-2.2.0+easy"
libraries[ting-client][destination] = "modules/ting/lib"

; Ding 2 modules
projects[ding_entity][type] = "module"
projects[ding_entity][download][type] = "git"
projects[ding_entity][download][url] = "git@github.com:ding2/ding_entity.git"
projects[ding_entity][download][tag] = "7.x-2.2.0"
