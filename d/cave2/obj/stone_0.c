 inherit ITEM;
void create()
{
    set_name("��ɫˮ��", ({ "crystal"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
                set("long",
            "һ����ʰ��,ɢ���������â��ˮ��ʯ�����������������ӬͷС�֣��ƺ��������������֡�\n");
                set("value", 2000);
                set("material", "stone");
                set("no_drop",1);
                set("no_sell",1);
                set("lore",1);
                set("skill", ([
                "name":         "literate",    
                "exp_required": 1000000,      
                "jing_cost":     50,     
                "difficulty":   50,     
                "max_skill":    50      
                ]) );
        }
    
}  
