 inherit ROOM;
void create()
{
        object ob;
        object table;
        set("short", "ʯ��");
        set("long", @LONG
�������ţ��ص��к�Ȼ�����˵ƹ⡣ǰ���ұڣ��ѱ����ʯ�Ƶ�ģ�������ﾹ
��ʮ����֮�࣬�������ӡ��ص���һֱ����ʪ���������ȴ�Ǹ����������һ
��ʯ��������һ��ʯ��������ʯ�ʡ�ʯ���Ի��и�ʯ�裬���ص��˫������֮�ƣ�
һ����Ȫ���������������������˳���������������˳�ȥ������ȴʼ�ձ�������
����ˮ��
LONG
        );
        set("exits",([
                "west" :__DIR__"hole",
                "down" :__DIR__"stone2",
        ]) );
        set("objects",([
                __DIR__"npc/yedi" : 1,
                __DIR__"obj/table" : 1,
                "/d/huanghe/yyd/npc/xiaoyaozi":1,
        ]) );
        set("resource/water",1);
        set("liquid/name","��Ȫˮ");
        set("liquid/type", "water");
        set("liquid/drunk_apply",6); 
        set("coor/x",2090);
        set("coor/y",-220);
        set("coor/z",-10);
        setup();
} 
void reset()
{
        object ob,yedi,table;
        object *inv;
        int i;
        ::reset();
        if (yedi=present("ye di",this_object()))
                yedi->delete_temp("marks/gived_reward");
        if (table=present("table",this_object()))
   {
                inv=all_inventory(table);
                for(i=0;i<sizeof(inv);i++)
                        if (inv[i]->query("id")=="powder") 
                                destruct(inv[i]);
                for(i=0;i<3;i++)
                {
                        ob=new(__DIR__"obj/powder");
                        ob->move(table);                        
                }
        }
}       
                
