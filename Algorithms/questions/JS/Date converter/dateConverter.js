const format = (
  seconds = null,
  minutes = null,
  hours = null,
  days = null,
  years = null
) => {
  let dayString = '',
    yearString = '',
    hourString = '',
    minuteString = '',
    secondString = '';
  if (years) {
    yearString += years === 1 ? `${years} year` : `${years} years`;
    if (hours === 0 && minutes === 0 && seconds === 0 && days !== 0)
      dayString += ' and ';
    dayString +=
      days === 1 ? `${days} day` : `${days === 0 ? '' : days + ' days'}`;
    if (minutes === 0 && seconds === 0 && hours !== 0) hourString += ' and ';
    hourString +=
      hours === 1 ? `${hours} hour` : `${hours === 0 ? '' : hours + ' hours'}`;
    if (seconds === 0 && minutes !== 0) minuteString += ' and ';
    minuteString +=
      minutes === 1
        ? `${minutes} minute`
        : `${minutes === 0 ? '' : minutes + ' minutes'}`;
    if (seconds) secondString += ' and ';
    secondString +=
      seconds === 1
        ? `${seconds} second`
        : `${seconds === 0 ? '' : seconds + ' seconds'}`;

    return (
      yearString +
      `${
        dayString.startsWith(' and') == true
          ? dayString
          : `${days === 0 ? '' : ', ' + dayString}`
      }` +
      `${
        hourString.startsWith(' and') === true
          ? hourString
          : `${hours === 0 ? '' : ', ' + hourString}`
      }` +
      `${
        minuteString.startsWith(' and') === true
          ? minuteString
          : ', ' + minuteString
      }` +
      `${
        secondString.startsWith(' and') === true
          ? secondString
          : `${seconds === 0 ? '' : ', ' + secondString}`
      }`
    );
  }

  if (days) {
    dayString += days === 1 ? `${days} day` : `${days} days`;
    if (minutes === 0 && seconds === 0 && hours !== 0) hourString += ' and ';
    hourString +=
      hours === 1 ? `${hours} hour` : `${hours === 0 ? '' : hours + ' hours'}`;
    if (seconds === 0 && minutes !== 0) minuteString += ' and ';
    minuteString +=
      minutes === 1
        ? `${minutes} minute`
        : `${minutes === 0 ? '' : minutes + ' minutes'}`;
    if (seconds) secondString += ' and ';
    secondString +=
      seconds === 1
        ? `${seconds} second`
        : `${seconds === 0 ? '' : seconds + ' seconds'}`;
    return (
      dayString +
      `${
        hourString.startsWith(' and') === true
          ? hourString
          : `${hours === 0 ? '' : ', ' + hourString}`
      }` +
      `${
        minuteString.startsWith(' and') === true
          ? minuteString
          : `${minutes === 0 ? '' : ', ' + minuteString}`
      }` +
      `${
        secondString.startsWith(' and') === true
          ? secondString
          : `${seconds === 0 ? '' : ', ' + secondString}`
      }`
    );
  }

  if (hours) {
    return `${hours} hour${
      minutes !== 0 || seconds !== 0
        ? ', ' +
          `${minutes} minute${
            seconds !== 0 ? ' and ' + seconds + ' ' + 'seconds' : 's'
          }`
        : ''
    }`;
  }
  if (minutes)
    return `${minutes} minute${
      seconds !== 0 ? ' and ' + seconds + ' ' + 'seconds' : 's'
    }`;
  if (seconds) return `${seconds} second`;
};
const formatDuration = seconds => {
  let minutes = 0;
  let hours = 0;
  let days = 0;
  let years = 0;
  if (seconds === 0) return 'now';
  if (seconds < 60) return format(seconds);
  else if (seconds >= 60 && seconds < 3600) {
    minutes = Math.floor(seconds / 60);
    seconds = seconds % 60;
    return format(seconds, minutes);
  } else if (seconds >= 3600 && seconds < 86400) {
    hours = Math.floor(seconds / 3600);
    minutes = Math.floor((seconds % 3600) / 60);
    seconds = (seconds % 3600) - minutes * 60;
    return format(seconds, minutes, hours);
  } else if (seconds >= 86400 && seconds < 31536000) {
    days = Math.floor(seconds / 86400);
    hours = Math.floor((seconds % 86400) / 3600);
    minutes = Math.floor(((seconds % 86400) % 3600) / 60);
    seconds = seconds - days * 86400 - minutes * 60 - hours * 3600;
    return format(seconds, minutes, hours, days);
  } else if (seconds >= 31536000) {
    years = Math.floor(seconds / 31536000);
    days = Math.floor((seconds % 31536000) / 86400);
    hours = Math.floor(((seconds % 31536000) % 86400) / 3600);
    minutes = Math.floor((((seconds % 31536000) % 86400) % 3600) / 60);
    seconds =
      seconds - years * 31536000 - days * 86400 - minutes * 60 - hours * 3600;
    return format(seconds, minutes, hours, days, years);
  }
};
