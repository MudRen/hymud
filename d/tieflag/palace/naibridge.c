 inherit ROOM;
void create()
{
        set("short", "�κ���");
        set("long", @LONG
�ӹ�����ʯ�񣬱�ֱ���У� ֻ��ǰ�澺��һ��Ϫ�����ϼܺ�ʯС�ţ�
���Ϻ�Ȼд���� ���κ��ţ� ���֣� ��Ŀ��ȥ�����κ��ţ��Ǳߣ��ֲ���һ
Ƭ������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"river",
  "north" : __DIR__"stonelin",
  "south" : __DIR__"ghost",
]));
        set("objects", ([
        __DIR__"obj/mirror" : 1,
                        ]) ); 
        set("outdoors", "palace"); 
    set("coor/x",160);
        set("coor/y",-30);
        set("coor/z",20);
        set("refresh_all_items", 1);
        setup();
   
} 
/*
void reset(){
        object obj;
        
        ::reset();
        if(!present("mirror", this_object())){
                obj = new(__DIR__"obj/mirror");
                if(objectp(obj)){
                        obj->move(this_object());
                }
        }       
        return;
}*/
