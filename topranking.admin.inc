<?php

function topranking_define_form_elements() {
  $factors = array(
    'design_status_1' => array(
      '#title' => t('Designs status 1'),
      '#description' => t('N = Aantal designs toegevoegd waarbij node status = 1'),
    ),
    'design_status_5' => array(
      '#title' => t('Designs status -5'),
      '#description' => t('N = Aantal designs toegevoegd waarbij node status = -5'),
    ),
    'design_status_4' => array(
      '#title' => t('Designs status 4'),
      '#description' => t('N = Aantal designs toegevoegd waarbij node status = 4'),
    ),
    'comments' => array(
      '#title' => t('Amount of comments'),
      '#description' => t('N = Aantal keer commentaar gegeven op een designs'),
    ),
    'login_count' => array(
      '#title' => t('Login count'),
      '#description' => t('N = Aantal keer ingelogd op de website'),
    ),
    'access_requests' => array(
      '#title' => t('Amount of access requests'),
      '#description' => t('N = Het aantal aanvragen ingediend'),
    ),
    'favourite_designer' => array(
      '#title' => t('Favourite designer'),
      '#description' => t('N = Het aantal keer geselecteerd als favoriete designer'),
    ),
    'winner' => array(
      '#title' => t('Winner'),
      '#description' => t('N = Het aantal keer geselecteerd als winnaar'),
    ),
    'days_membership' => array(
      '#title' => t('Days of membership'),
      '#description' => t('N = Aantal dagen dat gebruiker al lid is van de website'),
    ),
    'average_stars' => array(
      '#title' => t('Average number of rating stars'),
      '#description' => t('N = Aantal sterren dat een ingezonden design krijgt'),
    ),
    'design_status_10' => array(
      '#title' => t('Designs status 10'),
      '#description' => t('N = Aantal designs toegevoegd waarbij node status = 10'),
    ),
  );
  return $factors;
}

function topranking_set_x() {
  $form['intro'] =  array(
    '#markup' => t('De X-waarden zijn gebruikt om de gebruiker score te berekenen.
    Elke X-waarde moet tussen 1 en 20 zijn.'),
  );

  $factors = topranking_define_form_elements();

  foreach ($factors as $id => $base_field) {
    $form['x_' . $id] = $base_field + array(
      '#type' => 'textfield',
      '#default_value' => variable_get('x_' . $id, '1'),
    );
  }

  $form['#submit'][] = 'topranking_set_x_form_submit';

  return system_settings_form($form);

}

function topranking_set_x_validate($form, &$form_state){
  $factors = topranking_define_form_elements();

  foreach ($factors as $id => $base_field) {
    $value = $form_state['values']['x_' . $id];
    if (($value != '') && (!($value>0 && $value<21))) {
      form_set_error('x_' . $id, t('Value @value is not valid. Please enter the number between 1 and 20.',
      array('@value' => $value)));
    }

  }

}

function topranking_set_x_form_submit($form, $form_state){
  $factors = topranking_define_form_elements();

  foreach ($factors as $id => $base_field) {
    variable_set('x_' . $id, $form_state['values']['x_' . $id]);
  }

}
