 inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ͨ���̣ܶ�û�����͵���һ��ʯ�ҡ�����ֻ��һ�źܴ�ܴ��ʯ�Σ�
����һ����ʯͷ���ܳɵģ���Ȼ��ʯͷ���������ʸ���Ө����һ˿��ɫ
�����������ⶴ������֮����˼�������ֻҪ������ʯ���ϣ����̾���
��ů�紺����������ʯ�Σ�����֮�£�ֻ����Ҳ�Ҳ����ڶ�ֻ�ˣ�����
����ʯ��ȴ�ѱ�һ���������룡
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"mouseroom2",
                ]));
        set("objects", ([
                __DIR__"npc/star_horse" : 1,
                __DIR__"npc/star_tiger" : 1,
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
        if(dir == "northeast"){
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                        if (inv[i]->query("dungeon_npc")=="eren2")
                                return notify_fail(inv[i]->name()+"˵�����¶��۷����Ѿ����ˡ�\n");
                }
        }       
        return 1;
} 
