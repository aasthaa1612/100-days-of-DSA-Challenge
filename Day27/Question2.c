class Solution:
    def removeLoop(self, head):
        if head is None or head.next is None:
            return

        slow = head
        fast = head

        # Detect loop
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                break
        else:
            return

        # Find starting node of loop
        slow = head

        # Special case: loop starts at head
        if slow == fast:
            while fast.next != slow:
                fast = fast.next
            fast.next = None
            return

        while slow.next != fast.next:
            slow = slow.next
            fast = fast.next

        # Remove loop
        fast.next = None