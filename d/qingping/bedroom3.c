 //XXDER
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����Ƿ������ס������Ϊ�׼�����ֻ��һ�������Է���谮�����ڳ���
��������֮ѡ���������һ�����ڲ����Ӱټң������겻��ʮ�����ɶ������
֮�࣬��һ�㺢ͯ���죬�պ�سɴ������������һ�ȴ��ӣ���̨�ϰ���һ��
����ƿ��
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
      "down" : __DIR__"xting",
   ])); 
   set("objects", ([
      __DIR__"obj/bookcase": 1,
      __DIR__"obj/vase": 1,
   ]) );
   set("coor/x",170);
        set("coor/y",1990);
        set("coor/z",10);
        setup();
        
} 
void reset()
{
   object *inv;
   object item1, item2, bookcase;
   ::reset(); 
   bookcase = present("bookcase", this_object());
   inv = all_inventory(bookcase);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/books");
      item1->move(bookcase);
      item2 = new(__DIR__"obj/books");
      item2->move(bookcase);
   }
}    
