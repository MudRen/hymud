 // Room: /d/oldpine/tree3.c
inherit ROOM; 
void create()
{
        set("short", "��������");
        set("long", @LONG
������������������������ˣ�һ�������������˷�������
ʹ������Ŀ���������Ȼ��ľ�������������ֵط����¿���ʮ
�ֲ��ǵģ������㻹���̲�ס����һ�ۣ��������������Ҳ��ʮ
�塢���ɸߣ�һ����ѣ����������ڵ���ȥ��ǰ�뿪����ط���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tree2",
]));
        set("outdoors", "oldpine"); 
        set("coor/x",520);
        set("coor/y",2370);
        set("coor/z",130);
        setup();
        replace_program(ROOM);
}      
