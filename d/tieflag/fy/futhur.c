 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����������Ψһ�Ƚ������Ľ���������ɫ�ܹ֣�һ��Ѫɫ�����İ���ɫ������
���ǹ���ɭɭ�������޴���һյ�͵ƺ�����������̫������ͼΪ�׵���������׭��
�����ĸ��֡������Ѳ�����Ҳ�������޹�ĺ�ɫ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wcloud3",
]));
        set("objects", ([
        __DIR__"npc/dashi" : 1,
                        ]) ); 
        set("coor/x",-30);
        set("coor/y",10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
