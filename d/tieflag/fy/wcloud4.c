 inherit ROOM;
void create()
{
        set("short", "����·��");
        set("long", @LONG
���Ļ���·����������չ��·�ߵ�é�ݰ�С���ƾɣ��ֱߵ�����ɢ������
����Ż�ĸ�����·�ϵ�������Ƽ��ݣ���ƶ���������ϵ�ƣ��������ż����һ����
��ɫ����֮�ˣ����ڱǴҴҶ���������մ��һ���������·�ϲ�İ����ײĵ���ӭ
�ŷ��ż��ڱ�Ƥľ�ף���·����İ���ľ�����к�����һƬ��������������ʲô��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"afa",
  "south" : __DIR__"ansheng",
  "west"  : __DIR__"wcloud5",
  "east"  : __DIR__"wcloud3",
])); 
        set("objects", ([
        __DIR__"npc/beggar" : 3,
//        __DIR__"npc/honglianhua" : 1,
                        ]) ); 
        set("outdoors", "fengyun");
        set("coor/x",-40);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
