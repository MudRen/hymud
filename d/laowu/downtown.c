 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����ڱ��ϣ��ڻԻ͵ĵƻ�䣬����ĵƻ�ͱ��ϵĵƻ����ӳ��һյ�Ʊ����
յ�ƣ���յ�Ʊ����յ�ƣ��������ǹ���˸�������Ǿ����������ֵĽֵ�Ҳ�Ȳ��ϡ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"street",
  "southeast" : __DIR__"daroad",
]));
        set("outdoors", "laowu");
        set("objects", ([
        __DIR__"npc/beggar" : 2,
        __DIR__"npc/farmer" : 2,
        __DIR__"npc/drunk" : 2,
        __DIR__"npc/scavenger" : 2,
                        ]) );  
        set("coor/x",-10);
        set("coor/y",12050);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}        
