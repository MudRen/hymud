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
  "east" : __DIR__"bottom",
  "north" : __DIR__"bottom3",
  "up" : __DIR__"smalllake",
  "south" : __DIR__"bao",
])); 
        set("coor/x",200);
        set("coor/y",-20);
        set("coor/z",10);
        setup();
} 
int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i; 
        if( dir == "up" ) return 1;
        if( userp(me)) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) 
                        if((string)inv[i]->name() == "«έ")  return 1;
        }
        return notify_fail("\n������ؿڷ��ƣ����ǸϿ��ϰ��ĺã�\n");
}     
