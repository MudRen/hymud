 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�ƿ�һ��С�ţ���ǰͻȻ������ֻ��һ�������������ʮ�ɸߴ��ı�
���������������������֮������һ�����ң��������꽨�������������
Ȼ���ߣ���ɽ�ж�׼λ�ã�������ɡ�ʯ�������񴲡����������Σ�����
�̵����Ǿ��¡�
LONG
        );
        set("exits", ([ 
                "southeast" : __DIR__"palace4",
        ]));
        set("objects", ([
                __DIR__"obj/table" : 1,
                __DIR__"npc/baiyi" : 2,
        ]) );
        set("item_desc", ([
                "��": "һ�Ű��񴲡�\n",
                "����": "һ�Ű�����(table)�����ϻ����ż�ֻ����໨��(Bowl)��\n",
                "����": "һ�Ѱ����Ρ�\n",
                "bed": "һ�Ű��񴲡�\n",
                "table": "һ�Ű�����(table)�����ϻ����ż�ֻ����໨��(Bowl)��\n",
                "desk": "һ�Ű�����(table)�����ϻ����ż�ֻ����໨��(Bowl)��\n",
                "chair": "һ�Ѱ����Ρ�\n",
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
   object item1, item2, table;
   ::reset(); 
   table = present("table", this_object());
   inv = all_inventory(table);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/bowl");
      item1->move(table);
      item2 = new(__DIR__"obj/bowl");
      item2->move(table);
   }
}      
