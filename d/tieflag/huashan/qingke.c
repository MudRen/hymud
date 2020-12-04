 inherit ROOM;
void create()
{
        set("short", "���ƺ����");
        set("long", @LONG
����ˮ�����ٲ���ɽ·һת����ǰ��Ȼ���ʣ�һ��ƽ�س�������ǰ����������
��ɽ����ɫ�ľ���Ȫ��ʯ�����Ũ�����죬������ƣ�̨ͤ¥����ӳ���������У�
����������ɾ�֮�о���
LONG
        );
    set("exits", ([ 
                "northeast" : __DIR__"snowcave",
                "west" : __DIR__"shibapan2",
                "southup" : __DIR__"huixin",
        ])); 
        set("objects", ([
                __DIR__"obj/stone1" : 1,
                __DIR__"npc/woodcutter" : 1,
                __DIR__"npc/seller2" : 1,
        ]) );   
        set("outdoors", "huashanfy"); 
        set("coor/x",-580);
        set("coor/y",-70);
        set("coor/z",40);
        setup();
   
} 
void reset()
{
        object *inv;
        object item, obj;
        int i;
        
        ::reset(); 
        obj = present("stone", this_object());
        inv = all_inventory(obj);
        for (i=0;i<sizeof(inv);i++) {
                if (inv[i]->query("id")=="handkerchief") return;
        }
        item = new(__DIR__"obj/handkerchief");
           item->move(obj);
} 
