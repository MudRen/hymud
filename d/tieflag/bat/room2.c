 inherit ROOM;
void create()
{
        object con,item;
        set("short", "����");
        set("long", @LONG
����һ�������ĵ�������ս������ŵ�һ�ɴ̱ǵ�ҩ�ݵ�ζ����
��������ң��ƺ��ոձ��˷��������ָ�����ƿ�޶ѵĵ������ǡ�
��ǽ���Ÿ���ҩ�� 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"zoulang1",
]));
    set("objects", ([
      __DIR__"obj/case": 1,
      __DIR__"obj/drug" : 1,
       __DIR__"npc/xunluo2" : 1,
       
  ]) );
      set("coor/x",3290);
        set("coor/y",40);
        set("coor/z",-30);
        setup();
      con = present("case",this_object());
      item = present("drug",this_object());
      item->set_amount(10);
      item->move(con);
} 
int valid_leave(object me,string dir)
{
        object ob;
        if(userp(me) && me->query("class")!="bat" && dir == "south" && ob=present("xunluo shiwei",this_object()))
        if (ob->query("name")=="Ѳ������")
        {
        message_vision("$N��$n�����󵨣������Ҵ�����!\n",ob,me);
        return notify_fail("");
        }
        return 1;
}     
