 // Room: /d/chuenyu/foot_b_mtn.c
inherit ROOM; 
void create()
{
        set("short", "ɽ������");
        set("long", @LONG
���������ïʢ�ĵ������һ���峺���׵�СϪ���������������
�����æµ�š��ٱ����Ǻ���ɽ������ɽ�������ƺ����Կ���һ���ľ߹�
ģ�ĳǱ����Ǳ�����˲���һ����죬������������������Ľ��֣����ڡ�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"dustyroad2",
])); 
        set("objects", ([
               __DIR__"xiaojuan" : 1,
        ]) );
        //set("no_fight",1);
        //set("no_magic",1);
        set("outdoors", "chuenyu");
        set("coor/x",100);
        set("coor/y",130);
        set("coor/z",0);
        setup();
} 
void reset()
{
        object room;
        ::reset();
        if( room = find_object(__DIR__"sunnyroad"))
                if(room->query("exits/north"))
                        room->delete("exits/north");
}
int valid_leave(object me, string dir)
{
        if( query("exits/north"))
        call_out("close_path",10);
        return 1;       
} 
int close_path()
{
this_object()->reset();
return 1;
}    
