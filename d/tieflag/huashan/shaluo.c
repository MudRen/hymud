 inherit ROOM;
void create()
{
        set("short", "ɯ��ƺ����");
        set("long", @LONG
�˴�����ƽ̹����Ұ�������������ɹ��Ͱ��Ʒ�����ʯ�ͽ��Ϸ��󸣻��
������������������֥ʯ���������������ն����Ļ�Ԫ�֡�С�Ϸ�������������
ɽ������ΰͦ�Σ�˩��׮һ֦���㡣
LONG
        );
    set("exits", ([ 
                "southwest" : __DIR__"shibapan",
                "northwest" : __DIR__"wuli",
                "southup" : __DIR__"cave",
                "east" : __DIR__"bieyuan",
        ]));
        set("objects", ([
        ]));  
    set("outdoors", "huashanfy"); 
    set("coor/x",-575);
    set("coor/y",-40);
    set("coor/z",40);
        setup();
    replace_program(ROOM);
}      
