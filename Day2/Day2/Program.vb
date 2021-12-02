Imports System
Imports System.IO
Imports System.Text

Module Program

    Dim reader As New StreamReader("input.txt", Encoding.Default)
    Dim line As String
    Dim split_line As Object
    Dim direction As String
    Dim units As Integer
    Dim horizontal_pos As Integer
    Dim depth As Integer
    Dim result As Integer

    Dim horizontal_pos_part2 As Integer
    Dim depth_part2 As Integer
    Dim aim As Integer
    Dim result_part2 As Integer

    Sub Main(args As String())
        Console.WriteLine("Hello Day2!")
        horizontal_pos = 0
        depth = 0

        depth_part2 = 0
        aim = 0

        Do
            line = reader.ReadLine
            If String.IsNullOrEmpty(line) Then
                Continue Do
            End If
            split_line = Split(line, " ")
            direction = split_line(0)
            Int32.TryParse(split_line(1), units)
            'Console.WriteLine(direction)
            'Console.WriteLine(units)
            If StrComp(direction, "forward") = 0 Then
                horizontal_pos += units
                depth_part2 += (aim * units)
            End If
            If StrComp(direction, "down") = 0 Then
                depth += units
                'part2
                aim += units
            End If
            If StrComp(direction, "up") = 0 Then
                depth -= units
                'part2
                aim -= units
            End If
            'Console.WriteLine(depth)
            'Console.WriteLine(horizontal_pos)
        Loop Until line Is Nothing

        'Console.WriteLine(depth)
        'Console.WriteLine(horizontal_pos)
        result = depth * horizontal_pos
        result_part2 = depth_part2 * horizontal_pos


        Console.WriteLine(result)
        Console.WriteLine(result_part2)

    End Sub
End Module
