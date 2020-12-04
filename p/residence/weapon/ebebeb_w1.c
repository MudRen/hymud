// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit BLADE;

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

void create()
{
	set_name("[1;37mÎŞÓ°µ¶[2;37;0m", ({ "general blade", "blade" }));
	set_weight(5135);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "±ú");
		set("long", @LONG
ÏàË¼Ö®µ¶[2;37;0mÕâÊÇÒ»±úÓÉ·Ç³£¼áÓ²µÄ[1;32mÂÌÊ¯[2;37;0mÖÆ³É£¬ÖØÊ®½ï¶şÁ½ÆßÇ®µÄ[1;37mÏàË¼Ö®µ¶[2;37;0m¡£
×ÛºÏÆÀ¼Û[31mÍêÃÀ¾«ÖÂ[2;37;0m ¿´ÆğÀ´·Ç³£·æÀû£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[34mÏ¸Ëé[2;37;0m [36mÄ¾[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
[1;34mµç[2;37;0m:[35m±ê×¼[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[32m´Ö²Ú[2;37;0m ÌìÁé:[32m¼«²î[2;37;0m ¸£Ô´:[33mÒ»°ã[2;37;0m 
ÌìÔ¨:[33mÒ»°ã[2;37;0m ÌìĞş:[32m¼«²î[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÄ½ÈİÈË[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÈ­·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ebebeb");
		set("ownername", "Ä½ÈİÈË");
		set("value", 2000);
		set("weapon_prop/intelligence",3);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",6);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",8);
		set("weapon_prop/constitution",4);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 24);
    set("weapon_prop/jingli", 24);
    set("weapon_prop/damage", 0);

    set("wtypeA",2);
    set("wtypeB",8);
    set("wtypeC",0);
    set("wtypeD",1);
    set("wtypeE",2);
    set("wtypeF",8);
    set("wtypeG",2);
    set("wtypeH",5);
    set("wtypeI",3);
    set("wtypeJ",0);
    set("wtypeK",7);
    set("wtypeL",2);
    

                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 3);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_blade(397);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";