
// sword_book.c

inherit ITEM;

void create()
{
        set_name("���ƽ���", ({ "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"���ƺ���һ��ʲ�ὣ�׵�ǰ��ҳ����Ȼ��û�й����ʽ����ϸ��˵������\n"
                        "ǰ���йؽ������ܸ��뾫�嵹�ǲ��١�\n");
                set("value", 260);
                set("material", "paper");
                set("skill", ([
                        "name":                 "sword",        
                        "exp_required": 1000,
                        "jing_cost":             30,       
                        "difficulty":   20,   
                        "max_skill":    40    
                ]) );
        }
}

 
