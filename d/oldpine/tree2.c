 // Room: /d/oldpine/tree2.c
inherit ROOM; 
void create()
{
        set("short", "��������");
        set("long", @LONG
���������ʸ���һ��������������ϣ�����������Ѿ����ߡ�����
�ߣ������С�ĵ�����ȥ����������Ҳ��ȥ�������������Ͻ��������
���������󲿷ֶ������ɺ�Զ���㹻������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tree3",
  "down" : __DIR__"tree1",
])); 
        set("coor/x",520);
        set("coor/y",2370);
        set("coor/z",120);
        setup();
        replace_program(ROOM);
}  
