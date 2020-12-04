#include <ansi.h> 
#include <armor.h>

inherit SURCOAT;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;31m�϶Ǵ�[2;37;0m", ({ "bad surcoat", "surcoat" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
��֮�Ǵ�[2;37;0m����һ�����൱��Ӳ��[32m��ͭ[2;37;0m����[1;37m�޻�[2;37;0m�Ƴɣ������������Ǯ��[1;31m��֮�Ǵ�[2;37;0m��
�ۺ�����[32m����ϸ��[2;37;0m �������൱��̣�����[36mһ��[2;37;0m�ķ�������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[32m�ֲ�[2;37;0m [1;31mħ[2;37;0m:[31m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[32m�ֲ�[2;37;0m ��Դ:[32m����[2;37;0m 
��Ԩ:[33mһ��[2;37;0m ����:[33mһ��[2;37;0m 
��ʯ:[32m����[2;37;0m ����:[33mһ��[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m������[2;37;0m ������һЩ�� [1;32m�Ṧ[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yokarno");
		set("ownername", "������");
		set("value", 2000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",2);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 1);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 204);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 8);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",3);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "dodge",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		


		set("material", "default");
    set("sharpness", 3);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";