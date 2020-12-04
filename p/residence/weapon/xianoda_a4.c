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
	      set_name("[1;31m��а֮ѥ[2;37;0m", ({ "pixie boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
		set("long", @LONG
[1;31m��а֮ѥ[2;37;0m����һ˫���ޱȼ�Ӳ��[1;33m����[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ��ض��������Ǯ��[1;31m��а֮ѥ[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������ޱȼ�̣�����[36m��С[2;37;0m�ķ�������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;36m����[2;37;0m [40m��[2;37;0m:[1;36m����[2;37;0m [1;31mħ[2;37;0m:[1;34m����[2;37;0m [1;34m��[2;37;0m:[33m�ܸ�[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m��˫[2;37;0m ����:[34mϸ��[2;37;0m ��Ԩ:[34mϸ��[2;37;0m ����:[34mϸ��[2;37;0m 
��ʯ:[33m�ܸ�[2;37;0m ����:[33m�ܸ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mʷ�ٷ���[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xianoda");
		set("ownername", "ʷ�ٷ���");
		set("value", 16000);
		set("armor_prop/intelligence",24);
		set("armor_prop/strength",40);
		set("armor_prop/karey",16);
		set("armor_prop/percao",40);
		set("armor_prop/dexerity",21);
		set("armor_prop/constitution",8);
    set("armor_prop/dodge", 32);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 8);


    set("armor_prop/armor", 419);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 24);
    set("armor_prop/qi", 49);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 16);
    set("armor_prop/damage", 245);

    set("wtypeA",0);
    set("wtypeB",5);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",6);
    set("wtypeF",0);
    set("wtypeG",4);
    set("wtypeH",4);
    set("wtypeI",7);
    set("wtypeJ",7);
    set("wtypeK",0);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "blade",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";