 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����µ���ɳͻȻ������һ����ˬ��΢����������ֻ��һ��СС�ĺ�������
�������ǰ�������ˮ��Ȼֻ�ж�ָ��ȴ���峺���������������̲ݷҷ����ڿ�
�ȵ�ɳĮ�У���ˮ������ô��������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"desert9",
  "north" : "/d/loulan/sandlin",
  "east" : __DIR__"desert7",
]));
        set("objects", ([
                __DIR__"npc/thinlama" : 1,
        ]));
        set("resource/water",1);
        set("liquid", (["container": "��"]));
        set("outdoors", "quicksand"); 
        set("coor/x",-1085);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
}
// took out this by xxder because it caused some bug in guanwai Mache
/*
void init()
{
    object ob;
    string outexit;
    if( interactive( ob = this_player()))
    {
        if(query("exits/east")) delete("exits/east");
        outexit = __DIR__"desert"+(string)( random(3)+6)+ ".c";
        set("exits/east", outexit);
    }
}
*/     
