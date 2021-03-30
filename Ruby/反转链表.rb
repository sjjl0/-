class ListNode
  attr_accessor :val, :next

  def initialize(val = 0, _next = nil)
    @val, @next = val, _next
  end
end

head = ListNode.new(1,ListNode.new(2,ListNode.new(3,nil)))

class Solution
  def ReverseList(head)
    if head != nil
      arr = Array.new()
      # write code here
      this_node = head
      arr.push(this_node.val)
      while(this_node.next != nil) do
        this_node = this_node.next
        arr.push(this_node.val)
      end
      arr2 = Array.new()
      (0..arr.length).each do |i|
        arr2.push(arr[arr.length-1-i])
      end
      head2 = ListNode.new
      this_node2 = head2
      (0..arr2.length-2).each do |i|
        this_node2.val = arr2[i]
        if i != arr2.length-2
          this_node2.next = ListNode.new
        end
        if i != arr2.length-2
          this_node2 = this_node2.next
        end
      end
      return head2
    else
      return head
    end
  end
end