 // Room: /d/oldpine/npath1.c
inherit ROOM; 
void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG
������������һ���ּ��С·��������Զ���߳��������Ӿ�������
�裬С·���Գ����������ʵ���������Χ�ľ��񶼰��������������
�֡�����˵����������������ǧ�����������������顣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"npath2",
  "west" :"/d/taishan/baihe",
]));
        set("outdoors", "oldpine"); 
        set("coor/x",500);
        set("coor/y",2390);
        set("coor/z",100);
        setup();
        replace_program(ROOM);
}       
