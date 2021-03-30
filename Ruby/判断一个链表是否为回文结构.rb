# class ListNode
#   attr_accessor :val, :next
#
#   def initialize(val = 0, _next = nil)
#     @val, @next = val, _next
#   end
# end
#


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# @param head ListNode类 the head
# @return bool布尔型
#
class Solution
  def isPail(head)
    ju = 0
    p_head = head
    list_length = 0
    while p_head.next != nil
      list_length += 1
      p_head = p_head.next
    end
    half = (list_length/2).to_i
    arr = Array.new
    p = head
    i = 0
    while i < half
      arr.push(p.val)
      p = p.next
      i += 1
    end
    if list_length%2 == 1
      p = p.next
    end
    while half > 0
      if p.val != arr.shift
        ju += 1
      end
      p = p.next
      half -= 1
    end
    if ju == 0
      return true
    else
      return false
    end
  end
end