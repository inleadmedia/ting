<?php
/**
 * @file
 * Admin page callback file for the ting module.
 */

/**
 * Form builder; Configure ting settings for this site.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function ting_admin_ting_settings($form_state) {
  form_load_include($form_state, 'inc', 'ting', 'ting.admin');
  $form = array();

  $form['ting'] = array(
    '#type' => 'fieldset',
    '#title' => t('Ting service settings'),
    '#tree' => FALSE,
  );

  $form['ting']['ting_agency'] = array(
    '#type' => 'textfield',
    '#title' => t('Library code'),
    '#description' => t('The 6-digit code representing the library organization'),
    '#default_value' => variable_get('ting_agency', ''),
  );

  $form['ting']['ting_search_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Search service URL'),
    '#description' => t('URL to the Ting search webservice, e.g. http://opensearch.addi.dk/3.0/'),
    '#required' => TRUE,
    '#default_value' => variable_get('ting_search_url', ''),
  );

  $form['ting']['ting_recommendation_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Recommendation service URL'),
    '#description' => t('URL to the Ting recommendation webservice (Andre der har lånt...) , e.g. http://openadhl.addi.dk/1.1/'),
    '#required' => FALSE,
    '#default_value' => variable_get('ting_recommendation_url', ''),
  );

  $form['ting']['ting_enable_logging'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable logging'),
    '#default_value' => variable_get('ting_enable_logging', FALSE),
    '#weight' => 1,
  );

  $intervals = array(
    60,
    300,
    900,
    1800,
    3600,
    10800,
    43200,
    86400,
    259200,
    604800,
  );

  $options = array();
  foreach ($intervals as $interval) {
    $options[$interval] = format_interval($interval, 2);
  }

  $form['ting']['ting_cache_lifetime'] = array(
    '#type' => 'select',
    '#title' => t('Cache lifetime'),
    '#default_value' => variable_get('ting_cache_lifetime', TING_DEFAULT_CACHE_LIFETIME),
    '#options' => $options,
    '#description' => t("Cache answers from the datawell for this time. At least a few minutes is recommended, so the same objects doesn't have to be fetched on each page request."),
    '#weight' => 1,
  );

  $form['ting']['ting_search_profile'] = array(
    '#type' => 'textfield',
    '#title' => t('Search profile'),
    '#description' => t('Profile name, used for filtering the search based on settings from vip.dbc.dk.'),
    '#default_value' => variable_get('ting_search_profile', ''),
  );

  return system_settings_form($form);
}
