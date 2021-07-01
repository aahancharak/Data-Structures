export class G964 {
  public static mean = (town: string, strng: string) => {
    let avg: number = 0;
    let filterArr: string[] = strng
      .split('\n')
      .filter(ele => ele.split(':')[0] === town)
      .join('')
      .replace(':', ' ')
      .replace(/,/g, ' ')
      .split(' ')
      .filter(ele => parseFloat(ele));
    filterArr.forEach(ele => {
      avg += parseFloat(ele);
    });
    if (avg === 0) return -1;
    return avg / filterArr.length;
  };
  public static variance = (town: string, strng: string) => {
    let avg: number = 0;
    let filterArr: string[] = strng
      .split('\n')
      .filter(ele => ele.split(':')[0] === town)
      .join('')
      .replace(':', ' ')
      .replace(/,/g, ' ')
      .split(' ')
      .filter(ele => parseFloat(ele));
    filterArr.forEach(ele => {
      avg += parseFloat(ele);
    });
    avg = avg / filterArr.length;
    let result: number = 0;
    filterArr.forEach(ele => {
      result += Math.pow(parseFloat(ele) - avg, 2);
    });
    if (result === 0) return -1;
    return result / filterArr.length;
  };
}
