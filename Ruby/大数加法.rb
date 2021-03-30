#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
# 计算两个数之和
# @param s string字符串 表示第一个整数
# @param t string字符串 表示第二个整数
# @return string字符串
#
class Solution
  def solve(s, t)
    a = s.to_i
    b = t.to_i
    sum = a + b
    sum = sum.to_s
    return sum
  end
end