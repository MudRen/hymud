inherit ROOM;
void create()
{
        set("short", "�㳡��");
        set("long", @LONG
����Ƿ��Ƴ��������ֵ������ֵ�֮һ�����Ź㳡��һͷ������������������
�������ֵ����Ե����ڶ࣬������¡�����������Ȳ�����Ů���ǵĽ�Ц���������
����������ζ�����Ʋ˵���ζ����Ů�����ϵĻ���ζ��������Ŀѣͷ�Ρ���ֶ�
���ǳ������ľ�¥�����Ƹ��������Ǿ�����֡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fysquare",
  "north" : __DIR__"nwind2",
  "east" : __DIR__"fyge",
  "west" : __DIR__"jssju",
]));
        set("outdoors", "fengyun");
        set("objects", ([
        __DIR__"npc/zhu": 1,
                        ]) ); 
        set("coor/x",0);
        set("coor/y",10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
