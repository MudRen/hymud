 inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
һ��С·���������������졣·���Ա��Ƿ��ƳǵĻ��Ǻӣ��ӵ�����һ�߾�
�Ǹߴ�ķ��Ƴǳ�ǽ�ˡ���������Կ�����ǽ��ֵ�ڵ�ʿ����վ�ڡ��ӵ��ϳ���
���̲ݡ�΢�������һ�ɵ���������Ϣ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" :__DIR__"fywest",
  "southeast" : __DIR__"sroad2",
]));
        set("outdoors", "fengyun");
            replace_program(ROOM);
        set("coor/x",-160);
        set("coor/y",-50);
        set("coor/z",0);
        setup();
}   
