 inherit ROOM;
void create()
{
        set("short", "��ľΣ��");
        set("long", @LONG
����һ����Լ�ߴ�Ķ�ľ�ţ�����������������½�ͷ����ɣ�ֻ
Ҫһ��������һʧ�㣬���̱�Ҫ������ǡ����������Լ����ʮ���ɣ�
���¿����ͱ��絶�����ƾ���ӿ������ף�Ͷ��ʯ����ȥ��Ҳ������
������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"intersection",
  "west" : __DIR__"entrance",
]));
        set("outdoors", "palace"); 
        set("coor/x",150);
        set("coor/y",10);
        set("coor/z",20);
        setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        if( userp(me))
        {
        switch(random(20)){
                case 0:
                        message_vision("$N����һ�����ڶ�ľ���ϻ��˻Σ���\n",me);
                        return notify_fail("���ã�û����ȥ��\n");
                        break;
                case 1:
                        inv = all_inventory(me);
                        if(sizeof(inv)>=1)      
                        {
                                ob = inv[random(sizeof(inv))];
                if (ob->query("no_drop") || ob->query("owner")) break;
                                message_vision(ob->name()+"��$N���ϻ��˳���������������Ԩ��\n",me);
                                destruct(ob);
                   }
                        tell_object(me,"���ڶ�ľ����ǰ����ϵػ��ţ�����\n");
                        return 1;
                        break;
                default:
                        return 1;
                        break;
                        }
        return 1;
        }
        else
        return 1;
}        
