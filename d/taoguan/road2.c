 inherit ROOM;
void create()
{
        set("short", "ʯӢ��ʯ��");
        set("long", @LONG
����վ������ݵ����, ����ɫ����ʯӢ�ҽ������Ѷ���, ����
���ɽɫ���γ�һ������ɫ�ľ�����̧ͷ����ʯ�׾�ͷ����������, ��
Ȼ����������Ѿ������������ºۼ�, ���Բ�ʧ��ׯ����ʥ����Ϣ��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"putian",
  "northup" : __DIR__"road3",
  "southdown" : __DIR__"road1",
]));
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2010);
        set("coor/z",30);
        setup();
        replace_program(ROOM);
}       
