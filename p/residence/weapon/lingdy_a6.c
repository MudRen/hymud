#include <ansi.h> 
#include <armor.h>

inherit BOOTS;

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
	      set_name("[1;34m����֮ѥ[2;37;0m", ({ "good boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
		set("long", @LONG
����֮ѥ[2;37;0m����һ˫���ޱȼ�Ӳ��[1;37m����[2;37;0m����[1;33mľ�޻�[2;37;0m�Ƴɣ��ض���������Ǯ��[1;34m����֮ѥ[2;37;0m��
�ۺ�����[1;34m��������[2;37;0m �������ޱȼ�̣�����[36mһ��[2;37;0m�ķ�������
������˼����ŷ��ţ�
[31m��[2;37;0m:[1;36m����[2;37;0m [1;37m��[2;37;0m:[1;32mħ��[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m��ʥ[2;37;0m ����:[33mһ��[2;37;0m 
��ʯ:[34mϸ��[2;37;0m ����:[36m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m���[2;37;0m ������һЩ�� [1;32mȭ��[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lingdy");
		set("ownername", "���");
		set("value", 9000);
		set("armor_prop/intelligence",40);
		set("armor_prop/strength",40);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",32);
    set("armor_prop/dodge", 40);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 40);


    set("armor_prop/armor", 393);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 24);
    set("armor_prop/qi", 15);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 32);
    set("armor_prop/damage", 291);

    set("wtypeA",5);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",7);
    set("wtypeE",5);
    set("wtypeF",0);
    set("wtypeG",9);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 10);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";