 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����������˹�����ܣ���ľɢ����һ�������㣬��ܵļ���д���
С����������˸�ɫ��������ᣬ���СС��ƿ�ӣ��е������е���ʯ��
Ҳ�е����Ը��ֲ�ͬ��ľͷ��ɵġ���Щ���������ıڣ��迴�ƺ���Щ��
�ң��ٿ���ȴ�ַǳ����ţ��ֱ��£������Ǹ����׵��ˣ��߽������������
�������ᱻϴȥ���֡�
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"palace3",
                                ]));
        set("objects", ([
                __DIR__"obj/shelf" : 1,
                __DIR__"obj/vase" : 1,
                
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void reset()
{
   object *inv;
   object item1, item2, table,vase;
   ::reset(); 
   table = present("shelf", this_object());
   inv = all_inventory(table);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/yawnbook");
      item1->move(table);
   }
   vase = present("vase", this_object());
   inv = all_inventory(vase);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/senyao");
      item1->move(vase);
      item1 = new(__DIR__"obj/keeyao");
      item1->move(vase);
      item1 = new(__DIR__"obj/ginyao");
      item1->move(vase);
   }
} 
