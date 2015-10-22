# Google Auth

This 'gauth' module allows you to authenticate with google,
and use this authentication to carry other api requests.

This module provides functionality for use by other modules,
enabling users to manage accounts, authenticate with google
(i.e. get an access token) and use this authentication to 
perform api requests.

This module allows you to enter google account details like client id,
client secret key, developer key, and to select google services to be 
enabled. It then gets the OAuth2 access token from Google.

The account management page shows a authenticate link if the account 
is not authenticated and revoke link if the account is authenticated.

This is a port from the Drupal module of the same name. It contains
two sub-modules: gauth_login and gauth_user.

## Requirements

This module depends on the Google api php client library which you
need to download and install in your libraries folder.


## Installation

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules.
  
- Also install the Libraries module for Backdrop and add the Google
  API client library to your sites libraries folder in a 
  subdirectory 'google-api-php-client'.
  
- The full names of the three component modules which appear in
  Backdrop's Functionality/Modules listing in a section named
  'Google API' are:
  + Google Auth
  + Google Auth User Support
  + Google Login Support
  
- Each of these three component modules has configuration settings.


## Help & Documentation

See readme.txt for more information about installation and use.


## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.
    
        
## Current porting to Backdrop

Graham Oliver (github.com/Graham-72/)

## Credits

### Maintainer for Drupal:

- Sadashiv Dalvi (sadashiv)

### Acknowledgement

This port to Backdrop would not, of course, be possible without all
the work done by the developer and maintainer of the Drupal module.
