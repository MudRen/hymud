 inherit ROOM;
void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
һ���������ܲ����۵���·��������ǧ�����ʷ�У�������ʳ��
�����˵������������ǵİ׹����ڵ�·���ԡ�������������ô�Ĳ���
�ۣ��ƺ�һ������ĺ��Ӷ����Խ�����ڽ��¡�
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"huoyan",
  "southeast" : __DIR__"sichou5",
]));
        set("objects", ([
        __DIR__"npc/trader" : 3,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1020);
        set("coor/y",2020);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   