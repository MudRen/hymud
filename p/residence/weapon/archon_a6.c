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
	      set_name("[37mÕğµçÖ®ÏîÁ´[2;37;0m", ({ "zhendian neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "´®");
		set("long", @LONG
[37mÕğµçÖ®ÏîÁ´[2;37;0mÕâÊÇÒ»´®ÓÉÎŞ±È¼áÓ²µÄ[1;33m½ğÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØËÄ½ï¶şÁ½ËÄÇ®µÄ[37mÕğµçÖ®ÏîÁ´[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[36m²»Ğ¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[32mË®[2;37;0m:[1;35m¾øÊÀ[2;37;0m [33mÍÁ[2;37;0m:[35m±ê×¼[2;37;0m [1;35m·ç[2;37;0m:[1;33mÌìÊ¥[2;37;0m 
[1;37mÀ×[2;37;0m:[1;32mÄ§Íõ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31mÎŞË«[2;37;0m ¸£Ô´:[34mÏ¸Ëé[2;37;0m 
ÌìĞş:[36m²»´í[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 
°×Ê¯:[36m²»´í[2;37;0m ×ÏÊ¯:[34mÏ¸Ëé[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÌìÕı[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m¹÷·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "ÌìÕı");
		set("value", 16000);
		set("armor_prop/intelligence",24);
		set("armor_prop/strength",48);
		set("armor_prop/karey",23);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",24);
		set("armor_prop/constitution",16);
    set("armor_prop/dodge", 17);
    set("armor_prop/parry", 24);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 425);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 48);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 164);

    set("wtypeA",6);
    set("wtypeB",6);
    set("wtypeC",11);
    set("wtypeD",6);
    set("wtypeE",5);
    set("wtypeF",10);
    set("wtypeG",9);
    set("wtypeH",5);
    set("wtypeI",4);
    set("wtypeJ",4);
    set("wtypeK",0);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "club",
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