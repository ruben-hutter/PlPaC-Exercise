import Data.Char
main::IO()

data Tree = Leaf Int
          | Node Tree Int Tree

instance Eq Tree where
    Leaf l == Leaf m = l == m
    Node l1 v1 r1 == Node l2 v2 r2 = v1 == v2 && l1 == l2 && r1 == r2
    _ == _ = False

printTree::Tree -> String
printTree (Leaf l) = show l
printTree (Node l v r) = printTree l ++ show v ++ printTree r

main = do
    let myTree1 = Node (Node (Leaf 1) 3 (Leaf 4)) 5 (Node (Leaf 6) 7 (Leaf 9))
    print(printTree myTree1)
    let myTree2 = Node (Node (Leaf 1) 3 (Leaf 4)) 5 (Node (Leaf 6) 7 (Leaf 9))
    print(myTree1 == myTree2)
    