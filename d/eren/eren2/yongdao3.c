 inherit ROOM;
void create()
{
        set("short", "��");
        set("long", @LONG
�¶�������΢ƽ̹һЩ�����϶��˼�յ�͵ơ����������ʯ��ͨ���ѵ�ֻ��һ
�˿��Բ���������ʯ��վ�ż�������ɫ�¿����ˣ���������Ӱ֮�У�ֻ���ü���
����е����⡣
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"yongdao4",
                "southup" : __DIR__"yongdao2",
                "westup" : __DIR__"yongdao3a",
        ]));
        set("objects", ([
                __DIR__"npc/guarda" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(dir == "westup" || dir == "eastdown"){
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                        if (inv[i]->query("dungeon_npc")=="eren2")
                                return notify_fail(inv[i]->name()+"���ֵ�ס�����·��\n");
                }
        }       
        return 1;
}  
