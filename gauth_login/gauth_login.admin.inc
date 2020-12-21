<?php
/**
 * @file
 * Administration pages for GAuth Login settings.
 */


/**
 * Administrative settings.
 *
 * @return
 *   An array containing form items to place on the module settings page.
 */
function gauth_login_settings() {
  backdrop_set_title(t('Google Auth Login'));

  $config = config('gauth_login.settings');
  $form['#config'] = 'gauth_login.settings';

  $form['gauth_login_developer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API Key'),
    '#required' => TRUE,
    '#description' => t('The server API key of the web application.'),
    '#default_value' => $config->get('gauth_login_developer_key'),
  );
  $form['gauth_login_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client Id'),
    '#required' => TRUE,
    '#description' => t('The Client ID of the web application.'),
    '#default_value' => $config->get('gauth_login_client_id'),
  );
  $form['gauth_login_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Client Secret Key'),
    '#required' => TRUE,
    '#description' => t('The client secret key of the web application.'),
    '#default_value' => $config->get('gauth_login_client_secret'),
  );
  $form['gauth_login_prom_message'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prompt message to change password on first login.'),
    '#description' => t('If this option is enabled a new user will see a prompt message to change the password.'),
    '#default_value' => $config->get('gauth_login_prom_message'),
  );

  $css_path = backdrop_get_path('module', 'gauth_login') . '/css/';
  $button_style_options = array(
    'light' => '<img src="/' . $css_path . 'btn_google_signin_light_normal_web.png" class="google-button" />',
    'dark' => '<img src="/' . $css_path . 'btn_google_signin_dark_normal_web.png"  class="google-button" />',
  );

  $form['gauth_login_button_style'] = array(
    '#type' => 'radios',
    '#title' => t('Button style'),
    '#description' => t('Select the button style to use for the "Sign in with Google" button.'),
    '#options' => $button_style_options,
    '#default_value' => $config->get('gauth_login_button_style'),
    '#attached' => array(
      'css' => array(
        $css_path . 'gauth_login.settings.css',
      ),
    ),
  );

  $form['advanced_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced Settings'),
    '#description' => t(''),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['advanced_settings']['gauth_login_domain_restriction'] = array(
    '#type' => 'textfield',
    '#title' => t('Restrict to Domain'),
    '#description' => t('If you want to restrict the users to a specific domain to use logging in with Google insert your domain here. e.g., mycollege.edu. Note that this works only for Google Apps hosted accounts. Also note that if some user other than this domain tries to login with Google then they will face issues. Leave this blank if you are not sure how it works; an incorrect configuration will break Google login.'),
    '#default_value' => $config->get('gauth_login_domain_restriction'),
  );
  $form['advanced_settings']['gauth_login_create_user'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create new user if not found.'),
    '#description' => t('Create a new Backdrop account when a new user uses "Sign in with Google." If disabled, a new Backdrop account will not be created and instead the attempt will show a message to the user.'),
    '#default_value' => $config->get('gauth_login_create_user'),
  );
  $form['advanced_settings']['gauth_login_create_user_not_allowed_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Message to be shown when "Create new user" is disabled'),
    '#description' => t('Type in the message which should be shown to the user when "Create new user" is disabled and a new user attempts to sign in with Google.'),
    '#default_value' => $config->get('gauth_login_create_user_not_allowed_message'),
    '#states' => array(
      'visible' => array(
        ':input[name="gauth_login_create_user"]' => array('checked' => FALSE),
      ),
      'required' => array(
        ':input[name="gauth_login_create_user"]' => array('checked' => FALSE),
      ),
    ),
  );
  return system_settings_form($form);
}


/**
 * Validation handler for login settings.
 */
function gauth_login_settings_validate($form, $form_state) {
  if (!$form_state['values']['gauth_login_create_user'] && trim($form_state['values']['gauth_login_create_user_not_allowed_message']) == '') {
    form_set_error('gauth_login_create_user_not_allowed_message', t('Message to be shown is a required field.'));
  }
}
