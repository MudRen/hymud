 inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
����Ĺ�ľ������Щ������ʹ��ֲ���ǰ���ĵ�·��һ��С�ľͱ���֦�ҵ����ֽţ�
��ǰ���ֲ�֪ͨ������㲻������������֮�ġ�
LONG                                         
        );
        set("exits", ([
  "south" : __DIR__"troad1",
  "west" :  __DIR__"troad3",  
  "east" :  __DIR__"troad4",
])); 
        set("outdoors","tieflag");      
        set("coor/x",170);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",170);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",170);
        set("coor/y",0);
        set("coor/z",20);
        setup();
}
int valid_leave(object who,string dir)
{
        if(userp(who) && random(3))
        {
                who->move(this_object());
                return notify_fail(""); 
        }
        return 1;
}    
