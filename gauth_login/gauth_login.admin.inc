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
  $form['gauth_login_client_id'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Client Id'),
    '#required'      => TRUE,
    '#description' => t('The client id of google account.'),
    '#default_value' => config_get('gauth.settings','gauth_login_client_id'),
    '#description'   => t('Client id of the google drive app.'),
  );
  $form['gauth_login_client_secret'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Client Secret'),
    '#required'      => TRUE,
    '#description' => t('The client secret of google account.'),
    '#default_value' => config_get('gauth.settings','gauth_login_client_secret', ''),
    '#description'   => t('Client secret of the google drive app.'),
  );
  $form['gauth_login_developer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Api Key'),
    '#required' => TRUE,
    '#description' => t('The api key of google account.'),
    '#default_value' => config_get('gauth.settings','gauth_login_developer_key', ''),
  );

  // Add a submit button
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Submit handler for module_settings_form().
 */
function gauth_settings_form_submit($form, &$form_state) {
  $config = config('gauth.settings');
  $config->set('gauth_login_client_id', $form_state['values']['gauth_login_client_id']);
  $config->set('gauth_login_client_secret', $form_state['values']['gauth_login_client_secret']);
  $config->set('gauth_login_developer_key', $form_state['values']['gauth_login_developer_key']);
  $config->save();
  backdrop_set_message(t('The configuration options have been saved.'));
}
