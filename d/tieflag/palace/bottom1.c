 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����ʵ�ں������ܾ���Ȫˮ�峺��������ʽ��������Ϻ�������ǰ��
�е�������ȥ������ˮ����ɰʯ��������裬���ָо�����δ�������˾�
�����������Եõ��ġ�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"bottom",
  "eastup" : __DIR__"yadi",
  "north" : __DIR__"bottom3",
])); 
        set("coor/x",190);
        set("coor/y",-30);
        set("coor/z",10);
        setup();
} 
int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i; 
        if( dir == "eastup" ) return 1;
        if( userp(me)) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) 
                        if(inv[i]->name() == "«έ")  return 1;
        }
        return notify_fail("\n������ؿڷ��ƣ����ǸϿ��ϰ��ĺã�\n");
}    
