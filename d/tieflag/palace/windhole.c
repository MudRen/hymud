 inherit ROOM;
void create()
{
        set("short", "��Ѩ");
        set("long", @LONG
ɽ������ɫ���ʣ�����ɭɭ��ɽ���ڸ��������������������Ѽ���ָ.
���ں����絶����Х���������һ������ֻ���Ŀ����г�����Ѫ�ȣ�һ��
����ĸо�ӿ������ͷ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"interroad",
  "west" : __DIR__"ghost",
]));
        set("objects", ([
        __DIR__"obj/hulu" : 1,
                        ]) ); 
        set("outdoors", "palace"); 
        set("coor/x",170);
        set("coor/y",-40);
        set("coor/z",20);
        set("coor/x",170); 
        setup(); 
} 
void reset(){
        object obj;
        
        ::reset();
        if(!present("hulu", this_object())){
                obj = new(__DIR__"obj/hulu");
                if(objectp(obj)){
                        obj->move(this_object());
                }
        }       
        return;
}      
