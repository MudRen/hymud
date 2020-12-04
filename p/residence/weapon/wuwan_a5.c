#include <ansi.h> 
#include <armor.h>

inherit NECK;

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
	      set_name("[1;34mÎåÍò[2;37;0m", ({ "longquan neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "´®");
		set("long", @LONG
[31mÁúÈªÈË¼ä¼«Æ·£¬ÎäÁÖÖÁ±¦£¡
[2;37;0mÕâÊÇÒ»´®ÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0m¼ÓÉÏ[1;33mÁú¼ë²ÏË¿[2;37;0mÖÆ³É£¬ÖØËÄ½ï¾ÅÁ½ÆßÇ®µÄ[31mÁúÈªÖ®ÏîÁ´[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;31mÄ§[2;37;0m:[1;31m»ÙÌì[2;37;0m [36mÄ¾[2;37;0m:[1;32mÄ§Íõ[2;37;0m [32mË®[2;37;0m:[1;31m»ÙÌì[2;37;0m [1;35m·ç[2;37;0m:[1;32mÄ§Íõ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[1;36mÍêÃÀ[2;37;0m 
ÌåÁé:[1;32mÄ§Íõ[2;37;0m °×Ê¯:[1;36mÍêÃÀ[2;37;0m ×ÏÊ¯:[1;34m¾ÙÊÀ[2;37;0m ÉÁµç:[33mºÜ¸ß[2;37;0m 
³¤Éú:[1;36mÍêÃÀ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÎåÍò[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÖ¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wuwan");
		set("ownername", "ÎåÍò");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 76);
    set("armor_prop/parry", 82);
    set("armor_prop/attack", 72);


    set("armor_prop/armor", 366);
    set("armor_prop/defense", 94);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 75);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 72);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",15);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",9);
    set("wtypeG",12);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",15);
    
    
                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 21);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";