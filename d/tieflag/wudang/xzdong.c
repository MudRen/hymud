inherit ROOM;
void create()
{
        set("short", "�������");
        set("long", @LONG
���ߺ�ש��Χǽǰ��������������������ͭ���Ĵ��Ž���������
�������Ҹ�����һֻʯʨ��ʯʨ����̬���飬����͸�����ϵ�һ�У�
���κ��¶������⡣��ƽ����һ�굽ͷ�����ڼң������Ĵ����Ρ�
ֻ����ײŻ����������������֮�֡�
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"xzroad1",
        ]));
        set("coor/x",110);
        set("coor/y",-40);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
