 // Room: /d/oldpine/cliffside.c
inherit ROOM; 
void create()
{
        set("short", "�ּ�....��....���±�");
        set("long", @LONG
��������վ��һ�������ּ��С�յ��ϣ���ı��ߡ����ߡ��ϱ߶�
��ï�ܵ�������Ψ�������Ǹ����£�����̽ͷһ�������̲��������ص�
��һ��������������ɵ�ǧ��С�ģ�һ��С�ĵ�����ȥ�϶��Ƿ�����ǡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"pine2",
  "north" : __DIR__"pine1",
  "east" : __DIR__"pine1",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "cliff" : "�㶨������һ������ʵ�������û������������ֲ���Ҳ��
���Դ���������ɽ����ֻ���������ϴ��û�����ְ׳�Ը���
����ɵ�°ɡ�
",
]));
        set("outdoors", "oldpine"); 
        set("coor/x",540);
        set("coor/y",2340);
        set("coor/z",85);
        setup();
        replace_program(ROOM);
}      
