 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
ʯ�����ԣ������Ű���㾧Ө�⻬��ʯ�飬���������еƹ�͸��ȴ�Ʋ�
������Ƕ������ġ���ʯ���ĵ��ϣ�������һ�н�ӡ��ÿ�����ߣ�����һ����
�������ó���������ȥ�ģ�Ҳû����˹������롣�����е����̵�ʯͷ��
Ҳ������һ����ƽ����ʵ���������õ����̣�Ҳʮ�ֲ����ס������˵Ľ�ӡ
���ȵ��̵Ļ������
LONG
        );
        set("exits", ([ 
                "southdown" : __DIR__"yongdao7",
                "westup" : __DIR__"yongdao4",
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
