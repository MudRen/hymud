 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�鷿");
        set("long", @LONG
����û�д��ӣ���ʵ����һ�����׼���鷿���ͺ����ϴ����������
����ĵط���ȫһ�����鷿���������ڣ�����������������ܣ��м���
һ�ž��ŵĴ���ʯ����������������������ķ��ı���
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"yard2",
                "south" : __DIR__"innerroom",
                        ]));                    
        set("objects", ([
                __DIR__"npc/yulang" : 1,
                __DIR__"obj/shelf" : 1,
        ]) );
        set("item_desc", ([
                "����": "һ�ž��ŵĴ���ʯ����������������������ķ��ı���\n",
                "desk": "һ�ž��ŵĴ���ʯ����������������������ķ��ı���\n",
             
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object obj, string dir){
        int i;
        object son;
        if(dir == "south"){
                if (son=present("jiang yulang",this_object()))
                if (!userp(son))
                        return notify_fail("������˵���Ҹ�����ЪϢ���ݲ���͡�\n");
        }       
        return 1;
}  
void reset()
{
   object *inv;
   object item1, item2, table;
   ::reset(); 
   table = present("shelf", this_object());
   inv = all_inventory(table);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/paper");
      item1->move(table);
      item2 = new(__DIR__"obj/paper1");
      item2->move(table);
   }
}    
